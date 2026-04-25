## pip install pillow
## WAP to covert image into black and white using any high-level programming (c#, C++, python).

from PIL import Image

# Open image
image = Image.open('img/deer.jpeg')

# Convert to grayscale
gray = image.convert('L')

# Convert to black & white (binary)
bw = gray.point(lambda x: 0 if x < 128 else 255, '1')

# Save the image
bw.save('img/bw_deer.jpeg')

# Show image
bw.show()