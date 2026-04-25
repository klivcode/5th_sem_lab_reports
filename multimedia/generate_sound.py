## pip install simpleaudio numpy


import numpy as np
import simpleaudio as sa

fs = 44100
duration = 1
frequency = 440

t = np.linspace(0, duration, int(fs * duration), False)
tone = np.sin(frequency * t * 2 * np.pi)

audio = (tone * 32767).astype(np.int16)

play_obj = sa.play_buffer(audio, 1, 2, fs)
print("Sound generated successfully !!!")
play_obj.wait_done()
