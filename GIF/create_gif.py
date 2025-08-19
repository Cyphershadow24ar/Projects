# v3 means that we using the version 3 of the imageio library
import imageio.v3 as iio
from PIL import Image

filenames = ['neymar-jr.png', 'neymar-jr2.png']
images = []

# Open first image and get its size (all others will be resized to this)
base_img = Image.open(filenames[0])
base_size = base_img.size  # (width, height)

for filename in filenames:
    img = Image.open(filename).resize(base_size)  # resize to match
    images.append(img)

# Save as GIF
images[0].save(
    "Njr.gif",
    save_all=True,
    append_images=images[1:],
    duration=500,
    loop=0
)
