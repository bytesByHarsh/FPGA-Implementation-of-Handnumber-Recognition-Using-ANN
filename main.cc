#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <xhand_num_nn.h>
#include <xparameters.h>

float *XvecHW = (float *)0x40000000;
XHand_num_nn hand_nn;
XHand_num_nn_Config *hand_nn_cfg;
void init_hand_nn(){
	int status = 0;
	hand_nn_cfg = XHand_num_nn_LookupConfig(XPAR_HAND_NUM_NN_0_DEVICE_ID);
	if(hand_nn_cfg){
		status = XHand_num_nn_CfgInitialize(&hand_nn,hand_nn_cfg);
		if (status!=XST_SUCCESS){
			printf("Failed Initialization");
		}
	}
}

int main()
{
	init_platform();
	init_hand_nn();
	print("Starting The Handwritten Number Recognition Code....\n\r");
	//Remember to include 1 as bias
	float X[401]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2.7574e-006,0.0001467,-0.0019193,-0.0043315,-0.0017943,0.0001634,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.00077114,-0.0069836,-0.0077533,0.013575,0.0008141,-7.7444e-005,0,0,0,2.0425e-005,0.00025361,-0.0042556,-0.033996,-0.016527,0.00097443,0,0,0,4.8433e-018,0.00030382,-0.0098922,-0.0055393,0.43397,0.77022,0.35536,-0.032332,0,0,0,0.00038348,-0.012559,0.027661,0.3664,0.17391,-0.010678,0,0,0.00020084,-0.00093453,-0.017054,-0.0023941,0.44701,0.96411,1.0745,0.58202,-0.052911,0,0,0,-0.0078815,0.084025,0.72609,1.0131,0.68555,-0.02162,0,0.00021401,-0.0032846,-0.025621,0.098435,0.63985,0.99758,1.0309,0.91052,0.18072,-0.017675,0,0,0,-0.036795,0.59378,1.0392,0.95827,0.46921,-0.018481,0.0001873,-0.00367,-0.017208,0.25484,0.81658,1.0268,0.97041,0.93225,0.50934,-0.022613,0.00018936,0,0,0,-0.029882,0.46948,1.0295,0.69686,0.026006,-0.012146,-0.024799,-0.021453,0.39012,0.91736,1.0471,0.86914,0.36131,0.25568,0.072134,-0.0080863,7.4466e-005,0,0,0,-0.01104,0.1272,1.013,0.44468,-0.057573,-0.01048,0.13489,0.51976,0.95957,1.0375,0.77597,0.21135,-0.033208,-0.022106,-0.0077933,0.00044986,0,0,0,0,-0.011132,0.12868,1.0063,0.54683,0.055513,0.36371,0.81888,1.0389,1.0169,0.6106,0.081561,-0.017102,-0.0014705,-0.00051374,-0.0001787,1.9914e-005,0,0,0,0,-0.011387,0.13314,0.97345,0.95389,0.88409,0.96763,1.0405,0.89927,0.47324,0.031475,-0.021911,0.0001757,0.0001174,0,0,0,0,0,0,0,-0.0099256,0.10748,0.9405,1.0269,1.0439,0.9916,0.63453,0.18498,-0.027882,-0.0081827,0.00040339,0,0,0,0,0,0,0,0,0,-0.0029606,0.016031,0.43429,0.73245,0.57372,0.3821,0.011862,-0.027445,0.00057797,6.1147e-005,0,0,0,0,0,0,0,0,0,0,0.00016687,-0.0026625,-0.0089818,0.013486,-0.0047742,-0.017634,-0.0080731,0.00083619,-0.00071936,-0.0050434,2.5531e-005,0,0,0,0,0,0,0,0,0,9.4975e-006,3.268e-006,-0.0018588,-0.0041457,-0.002676,-0.001277,4.7386e-005,-0.00072028,0.008295,0.057494,-0.00029105,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-0.0015478,0.017645,0.1213,-0.00061911,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2.5531e-005,-0.00029105,-0.0020173,1.0212e-005,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<401;i++){
		XvecHW[i] = X[i];
	}
	int num;
	XHand_num_nn_Set_y(&hand_nn,2);
	XHand_num_nn_Start(&hand_nn);
	while(!XHand_num_nn_IsDone(&hand_nn));
	num = XHand_num_nn_Get_return(&hand_nn);

	printf("Number is: %d \n",num);

	cleanup_platform();
	return 0;
}