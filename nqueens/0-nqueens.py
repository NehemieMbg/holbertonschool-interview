#!/usr/bin/python3


"""
n-queens problem solved using backtracking
"""


from sys import argv, exit


def solve_puzzle(N):
    board = [['.' for _ in range(N)] for _ in range(N)]
    solutions = []
    place_queen(0, board, solutions)
    return solutions


def place_queen(row, board, solutions):
    N = len(board)
    if row == N:
        queens = [[r, c] for r in range(N) for c in range(N)
                  if board[r][c] == 'Q']
        solutions.append(queens)
        return
    for col in range(N):
        if is_safe(row, col, board):
            board[row][col] = 'Q'
            place_queen(row + 1, board, solutions)
            board[row][col] = '.'


def is_safe(row, col, board):
    N = len(board)

    # is there a queen in the same column ?
    for i in range(row):
        if board[i][col] == 'Q':
            return False
    # chek in diagonal upper left
    i = row - 1
    j = col - 1
    while i >= 0 and j >= 0:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j -= 1
    # check upper right diagonal
    i, j = row - 1, col + 1
    while i >= 0 and j < N:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j += 1
    return True


if __name__ == "__main__":
    if len(argv) != 2:
        print("Usage: nqueens N")
    else:
        try:
            N = int(argv[1])
            if N < 4:
                print("N must be at least 4")
                exit(1)
            solutions = solve_puzzle(N)
            for sol in solutions:
                print(sol)
        except ValueError:
            solutions = []
            print("N must be a number")
            exit(1)
