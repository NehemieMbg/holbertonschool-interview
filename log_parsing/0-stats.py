#!/usr/bin/python3
import sys

# Initialize variables
total_file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

# Read stdin line by line
for line in sys.stdin:
    # Parse line
    try:
        parts = line.strip().split()
        ip_address = parts[0]
        status_code = int(parts[8])
        file_size = int(parts[9])
    except:
        # Skip line if format is not as expected
        continue

    # Update variables
    total_file_size += file_size
    status_codes[status_code] += 1
    line_count += 1

    # Print statistics after every 10 lines or keyboard interruption
    if line_count % 10 == 0:
        print(f'Total file size: {total_file_size}')
        for code in sorted(status_codes):
            if status_codes[code] > 0:
                print(f'{code}: {status_codes[code]}')

    # Handle keyboard interruption
    try:
        signal.signal(signal.SIGINT, lambda signal, frame: sys.exit(0))
    except KeyboardInterrupt:
        print(f'Total file size: {total_file_size}')
        for code in sorted(status_codes):
            if status_codes[code] > 0:
                print(f'{code}: {status_codes[code]}')
        sys.exit(0)

# Print final statistics
print(f'Total file size: {total_file_size}')
for code in sorted(status_codes):
    if status_codes[code] > 0:
        print(f'{code}: {status_codes[code]}')
