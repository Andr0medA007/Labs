import random

Infinity = 1000000000000



def find_min_roads(matrix): #умножение на саму себя
    list_of_points = []
    old_matrix = read_matrix_from_file("Matrix_Mass/g42.txt")
    new_matrix = [[Infinity for _ in range(10)] for _ in range(10)]
    for i in range(0,10):
        for j in range(0,10):
            for k in range(0,10):
                if (matrix[i][k] * old_matrix[k][j]) != 0:
                    list_of_points.append(matrix[i][k]+old_matrix[k][j])
            if len(list_of_points) != 0:
                new_matrix[i][j] = min(list_of_points)
            else:
                new_matrix[i][j] = 0
            list_of_points = []
    return new_matrix

def find_max_roads(matrix):
    list_of_points = []
    old_matrix = read_matrix_from_file("Matrix_Mass/g42.txt")
    new_matrix = [[_ for _ in range(10)] for _ in range(10)]
    for i in range(0, 10):
        for j in range(0, 10):
            for k in range(0, 10):
                if (matrix[i][k] * old_matrix[k][j]) != 0:
                    list_of_points.append(matrix[i][k] + old_matrix[k][j])
            if len(list_of_points) != 0:
                new_matrix[i][j] = max(list_of_points)
            else:
                new_matrix[i][j] = 0
            list_of_points = []
    return new_matrix

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=' ')
        print()
    print()

def read_matrix_from_file(filename):
    matrix = []
    with open(filename, 'r') as file:
        for line in file:
            row = list(map(int, line.split()))
            matrix.append(row)
    for i in range(len(matrix)):
        matrix[i][i] = 0
    return matrix


def generate_matrix():
    matrix = [[0 for _ in range(10)] for _ in range(10)]
    for i in range(10):
        for j in range(10):
            matrix[i][j] = random.randint(0,10)
    for i in range(len(matrix)):
        matrix[i][i] = 0
    return matrix

def main():
    minmax_flag = int(input("Введите вектор поиска: (min - 0/max - 1): "))
    n = int(input("Введите длину пути: "))
    matrix = read_matrix_from_file("Matrix_Mass/g42.txt")
    print_matrix(matrix)

    if minmax_flag == 0:
        for i in range(n-1):
            matrix = find_min_roads(matrix)
        print_matrix(matrix)
    if minmax_flag == 1:
        for i in range(n-1):
            matrix = find_max_roads(matrix)
        print_matrix(matrix)

if __name__ == "__main__":
    main()