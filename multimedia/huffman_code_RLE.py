import heapq
from collections import Counter

# ---------------- HUFFMAN CODING ---------------- #

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_tree(text):
    freq = Counter(text)
    heap = [Node(ch, f) for ch, f in freq.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(heap, merged)

    return heap[0]

def generate_codes(node, code="", codes={}):
    if node is None:
        return

    if node.char is not None:
        codes[node.char] = code

    generate_codes(node.left, code + "0", codes)
    generate_codes(node.right, code + "1", codes)

    return codes

def huffman_encode(text, codes):
    return ''.join(codes[ch] for ch in text)

def huffman_decode(encoded, root):
    result = ""
    current = root

    for bit in encoded:
        current = current.left if bit == '0' else current.right
        if current.char is not None:
            result += current.char
            current = root

    return result


# ---------------- RLE ---------------- #

def rle_encode(data):
    result = ""
    count = 1

    for i in range(1, len(data)):
        if data[i] == data[i - 1]:
            count += 1
        else:
            result += str(count) + data[i - 1]
            count = 1

    result += str(count) + data[-1]
    return result

def rle_decode(data):
    result = ""
    count = ""

    for ch in data:
        if ch.isdigit():
            count += ch
        else:
            result += ch * int(count)
            count = ""

    return result


# ---------------- MENU ---------------- #

while True:
    print("\n--- Compression Menu ---")
    print("1. Huffman Coding")
    print("2. Run-Length Encoding (RLE)")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        text = input("Enter text: ")
        root = build_tree(text)
        codes = generate_codes(root, "", {})

        encoded = huffman_encode(text, codes)
        decoded = huffman_decode(encoded, root)

        print("Codes:", codes)
        print("Encoded:", encoded)
        print("Decoded:", decoded)

    elif choice == '2':
        text = input("Enter text: ")

        encoded = rle_encode(text)
        decoded = rle_decode(encoded)

        print("Encoded:", encoded)
        print("Decoded:", decoded)

    elif choice == '3':
        print("Exiting program...")
        break

    else:
        print("Invalid choice! Try again.")