#! usr/bin/bash

# Define the input directory and output directory
INPUT_DIR="/home/parallels/Documents/Projects/low_level/rotate"
OUTPUT_DIR="output_img"
ANGLE=90

# Check if the input directory exists
if [ ! -d "$INPUT_DIR" ]; then
    echo "Input directory $INPUT_DIR does not exist."
    exit 1
fi

# Create the output directory if it does not exist
if [ ! -d "$OUTPUT_DIR" ]; then
    mkdir "$OUTPUT_DIR"
    echo "Created output directory $OUTPUT_DIR."
fi

# Loop through all files in the input directory
for FILE in "$INPUT_DIR"/*; do
    if [ -f "$FILE" ]; then
        BASENAME=$(basename "$FILE")
        OUTPUT_FILE="$OUTPUT_DIR/$BASENAME"
        
        # Use ImageMagick to rotate the image
        convert "$FILE" -rotate "$ANGLE" "$OUTPUT_FILE"
        
        echo "Rotated $FILE by $ANGLE degrees and saved as $OUTPUT_FILE."
    fi
done

echo "All images processed."