# Episode 5: Descriptor Matching and Object Detection
Use features and descriptors to track the car from the first frame as it moves from frame to frame. Store (ORB) descriptors in a Mat and match the features with those of the reference image as the video plays. Learn to filter out extraneous matches with the RANSAC algorithm. Then multiply points by a homography matrix to create a bounding box around the identified object. The result isn’t perfect, but try different filtering techniques and apply optical flow to improve on the sample implementation. Getting good at computer vision requires both parameter-tweaking and experimentation.

[Video](https://www.youtube.com/watch?v=hKq9KATD_EI)

The code as explained in the video doesn't work, or at least I could not reproduce it, but I found [this](https://devtalk.nvidia.com/default/topic/1026243/jetson-tx1/orbfeaturedetector-problem-when-using-opencv/) with a working code. The code transform the [cars.mp4](./cars.mp4) into a video where the features are highlighted and car bounding box is shown [cars_features](./cars_features.avi). Mostly, the code could not find the car, but...

<iframe width="560" height="315" src="https://www.youtube.com/embed/BY0LwP_Upkg" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>