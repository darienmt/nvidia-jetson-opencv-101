# Episode 4: Feature Detection and Optical Flow
Take an input MP4 video file (footage from a vehicle crossing the Golden Gate Bridge) and detect corners in a series of sequential frames, then draw small marker circles around the identified features. Watch as these demarcated features are tracked from frame to frame. Then, color the feature markers depending on how far they move frame to frame. This simplistic analysis allows points distant from the camera—which move less—to be demarcated as such.

[Video](https://www.youtube.com/watch?v=WjtJmb9dROQ)

## Step 1 : Detecting features on a video
Using  [ORB (oriented BRIEF)](https://docs.opencv.org/trunk/db/d95/classcv_1_1ORB.html) keypoint detector. The video I used was the [SDCND Vehicle Detection project](https://github.com/darienmt/CarND-Vehicle-Detection-P5). The video is [car_features.mp4](./car_features.mp4)

<iframe width="560" height="315" src="https://www.youtube.com/embed/be4XWshsTik" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

## Step 2 : Optical flow

Optical flow for sparse feature-set using the iterative [Lucas-Kanade method with pyramids](https://docs.opencv.org/2.4/modules/video/doc/motion_analysis_and_object_tracking.html). The video is [car_flow_1.mp4](./car_flow_1.mp4)

<iframe width="560" height="315" src="https://www.youtube.com/embed/EakrWZmOAs0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

Then the "distance" to the feature point is estimated using the feature point difference norm. The video is [car_flow_2.mp4](./car_flow_2.mp4)

<iframe width="560" height="315" src="https://www.youtube.com/embed/x-Pwxf90lhE" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

