#!/usr/bin/python3
def validUTF8(data):
    # Number of bytes remaining for the current UTF-8 character
    remaining_bytes = 0

    for byte in data:
        # Check if the current byte is a continuation byte
        if remaining_bytes > 0 and (byte >> 6) == 0b10:
            remaining_bytes -= 1
        # Check if the current byte is a leading byte
        elif remaining_bytes == 0:
            # Determine the number of bytes for the current UTF-8 character
            if (byte >> 7) == 0b0:
                remaining_bytes = 0  # 1-byte character
            elif (byte >> 5) == 0b110:
                remaining_bytes = 1  # 2-byte character
            elif (byte >> 4) == 0b1110:
                remaining_bytes = 2  # 3-byte character
            elif (byte >> 3) == 0b11110:
                remaining_bytes = 3  # 4-byte character
            else:
                return False  # Invalid leading byte
        else:
            return False  # Invalid continuation byte

    # Check if all characters have been fully decoded
    return remaining_bytes == 0
