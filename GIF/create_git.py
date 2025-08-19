# v3 means that we using the version 3 of the imageio library
import imageio.v3 as iio

filenames = ['neymar-jr.png', 'neymar-jr2.png']
images = [ ]

for filename in filenames:
  images.append(iio.imread(filename))

iio.imwrite('Njr.gif', images, duration = 500, loop = 0)

# TO RUN :
# Open the Terminal and run: python3 create_gif.py
# Make sure you have the imageio and Pillow libraries installed.
