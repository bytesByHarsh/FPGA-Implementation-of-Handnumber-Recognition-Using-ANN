# FPGA-Implementation-of-Handnumber-Recognition-Using-ANN
Implementation of Deep Learning and Machine Learning Algorithms is always a challenge as they consume a lot of resources and power. In this paper, we have presented a very simple yet efficient way for creating an IP (intellectual property) core for Handwritten Number Recognition for FPGAs. The proposed ANN was verified and compared with several ANN networks on MATLAB, which gave the accuracy of about 99.38%. This network was implemented on Xilinx Zybo board XC7Z010CLG400-1. The total area covered by the IP block is 27.9%. The IP created is efficient and uses fewer resources thus suitable for other embedded applications.

## Implementation

[core.cpp](core.cpp) is the Vivado HLS implementation.

[hand_num_nn.vhd](hand_num_nn.vhd) is the IP core generated from Vivado HLS that can integrated in IP integrator.

Refer [youtube link](https://www.youtube.com/watch?v=2EgtvmdpA6o) and [blog](http://www.harshmittal.co.in/tutorials/IEEE-2019/) for detailed explanation.

## Links
Blog Link: [http://www.harshmittal.co.in/tutorials/IEEE-2019/](http://www.harshmittal.co.in/tutorials/IEEE-2019/)

YouTube Tutorial: [https://www.youtube.com/watch?v=2EgtvmdpA6o](https://www.youtube.com/watch?v=2EgtvmdpA6o)

Paper Link: [https://ieeexplore.ieee.org/document/9015236](https://ieeexplore.ieee.org/document/9015236)


## Citation
```
@INPROCEEDINGS{9015236,  
  author={Mittal, Harsh and Sharma, Abhishek and Perumal, Thinagaran},  
  booktitle={2019 IEEE 8th Global Conference on Consumer Electronics (GCCE)},   
  title={FPGA Implementation of Handwritten Number Recognition using Artificial Neural Network},   
  year={2019}, 
  pages={1010-1011}, 
  doi={10.1109/GCCE46687.2019.9015236}}
```
