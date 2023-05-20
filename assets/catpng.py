import argparse
import os
from PIL import Image

# Set the output filename and format
output_filename = "concatenated.png"
output_format = "PNG"

# Set the desired spacing between images
spacing = 0

# Function to concatenate PNG images on the right side
def concatenate_images(directory):
    # Get the list of PNG images in the directory
    png_images = [f for f in os.listdir(directory) if f.endswith(".png")]

    # Sort the list of images alphabetically
    png_images.sort()

    # Get the dimensions of the first image in the list
    first_image = Image.open(os.path.join(directory, png_images[0]))
    width, height = first_image.size

    # Calculate the dimensions of the output image
    output_width = (width + spacing) * len(png_images) - spacing
    output_height = height

    # Create a new image with the calculated dimensions
    output_image = Image.new("RGBA", (output_width, output_height), (255, 255, 255, 0))

    # Iterate over the list of images and paste them into the output image
    x_offset = 0
    for png_image in png_images:
        image = Image.open(os.path.join(directory, png_image))
        output_image.paste(image, (x_offset, 0))
        x_offset += width + spacing

    # Save the output image
    output_path = os.path.join(directory, output_filename)
    output_image.save(output_path, format=output_format)
    print(f"Saved concatenated image to {output_path}")

# Parse command-line arguments
parser = argparse.ArgumentParser(description='Concatenate multiple PNG images on the right side')
parser.add_argument('directory', help='The directory containing the PNG images')
args = parser.parse_args()

# Concatenate images in the specified directory
concatenate_images(args.directory)