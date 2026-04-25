# Given values
sampling_rate = 44100   # Hz
duration = 30           # seconds
bit_depth = 8           # bits
channels = 2            # stereo

# Calculate file size in bytes
file_size = sampling_rate * duration * bit_depth * channels // 8

# Display result
print("File size =", file_size, "bytes")