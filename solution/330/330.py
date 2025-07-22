def Text_reader(text):
    result = []
    for char in text:
        if 'a' <= char <= 'z':
            shift = ord(char) + 13
            if shift > ord('z'):
                shift -= 26
            result.append(chr(shift))
        elif 'A' <= char <= 'Z':
            shift = ord(char) + 13
            if shift > ord('Z'):
                shift -= 26
            result.append(chr(shift))
        else:
            result.append(char)
    return ''.join(result)

with open('encoded.txt', 'r', encoding='utf-8') as file:
    encoded_text = file.read()

result = Text_reader(encoded_text)
# result содержит расшифрованный результат
