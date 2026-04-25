## pip install pillow

from PIL import Image

# Open image
image = Image.open('img/duck.jpg')

# Compress and save image
# quality ranges from 0 (lowest) to 100 (highest)
image.save('img/compressed_duck.jpg', optimize=True, quality=30)

print("Image compressed successfully!")