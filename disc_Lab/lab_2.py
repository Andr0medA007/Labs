import random
from sys import flags

import numpy as np

def matrix_input_random():
    size = int(input("Размер матрицы: "))
    matrix = [[0 for r in range(size)] for c in range(size)]
    for row in range(size):
        for col in range(size):
            matrix[row][col] = random.randint(0,1)
    return matrix

def matrix_input_cur():
    size = int(input("Размер матрицы: "))
    matrix = [[0 for r in range(size)] for c in range(size)]
    for row in range(size):
        for col in range(size):
            matrix[row][col] = int(input(f"Введите число {row}, {col}: "))
    return matrix


def matrix_print(matrix):
    for r in range(len(matrix)):
        for c in range(len(matrix[0])):
            print(f'{matrix[r][c]}', end=' ')
        print('')

def check_reflexive(matrix):
    first_flag = True
    zero_flag = True
    for r in range(len(matrix)):
        if matrix[r][r] != 1:
            first_flag = False

    for r in range(len(matrix)):
        if matrix[r][r] != 0:
            zero_flag = False
    if first_flag:
        print("Отношение рефлексивно")
    elif zero_flag:
        print("Отношение антирефлексивно")
    else:
        print("Отношение нерефлексивно")



def check_transitive(matrix):
    n = len(matrix)
    is_transitive = True
    is_anti_transitive = True
    is_non_transitive = False

    for i in range(n):
        for j in range(n):
            for k in range(n):
                if matrix[i][j] == 1 and matrix[j][k] == 1:
                    if matrix[i][k] != 1:
                        is_transitive = False
                    if matrix[i][k] == 1:
                        is_anti_transitive = False
                    if matrix[i][k] == 0:
                        is_non_transitive = True

    if is_transitive:
        print("Отношение транзитивно")
    elif is_anti_transitive:
        print("Отношение антитранзитивно")
    elif is_non_transitive:
        print("Отношение нетранзитивно")
    else:
        print("Неопределенно (смешанное поведение)")

def check_full(matrix):
    n = len(matrix)
    flag = True
    for i in range(n):
        for j in range(i):
            if matrix[i][j] == 0 and matrix[j][i] == 0:
                flag = False
    if flag:
        print("Отношение связно")
    else:
        print("Отношение несвязно")

def check_matrix_symmetry(matrix):
    flag_a = True
    flag_sym = True
    main_di = True
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] == 1 and j!=i:
                if matrix[j][i] == 0:
                    flag_sym = False
                if matrix[j][i] != 0:
                    flag_a = False
                if matrix[i][i] == 1:
                    main_di = False
    if flag_sym:
        print("Отношение симметрично")
        return
    if flag_a and main_di:
        print("Отношение асимметрично")
        return
    if flag_a:
        print("Отношение антисимметрично")
        return
    print("Не имеет симметрии")



def read_matrix_from_file(filename):
    matrix = []
    with open(filename, 'r') as file:
        for line in file:
            row = list(map(int, line.split()))
            matrix.append(row)
    return matrix

def write_matrix_to_file(matrix, filename):
    with open(filename, 'w') as file:
        for row in matrix:
            file.write(" ".join(map(str, row)) + '\n')


def main():
    matrix = read_matrix_from_file("m8.txt")
    matrix_print(matrix)
    check_reflexive(matrix)
    check_transitive(matrix)
    check_matrix_symmetry(matrix)
    check_full(matrix)
    write_matrix_to_file(matrix,"Final")

if __name__ == "__main__":
    main()