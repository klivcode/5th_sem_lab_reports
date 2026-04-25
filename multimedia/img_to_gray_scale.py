## WAP to covert image into gray scale using any high-level programming (c#, C++, python).  

## pip install opencv-python

import cv2

# Read the image
image = cv2.imread('img/tiger.jpg')

# Check if image loaded successfully
if image is None:
    print("Error: Image not found. Check the path!")
else:
    # Convert to grayscale
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Save the grayscale image
    cv2.imwrite('img/gray_tiger.jpg', gray_image)

    # Display images
    cv2.imshow('Original Image', image)
    cv2.imshow('Grayscale Image', gray_image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()