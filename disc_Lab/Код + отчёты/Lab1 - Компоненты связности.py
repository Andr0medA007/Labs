import numpy as np

def read_matrix_from_file(filename):
    matrix = []
    with open(filename, 'r') as file:
        for line in file:
            row = list(map(int, line.split()))
            matrix.append(row)
    for i in range(len(matrix)):
        matrix[i][i] = 1
    return matrix

def matrix_equals(matrix):
    matr1 = np.array(matrix)
    print(matr1.dot(matr1))
    return matr1.dot(matr1)
    
def matrix_downgrade(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] != 0:
                matrix[i][j] = 1
    return matrix

def matrix_sum(matrix1, matrix2):
    for i in range(len(matrix1)):
        for j in range(len(matrix2)):
            matrix1[i][j] += matrix2[i][j]
    return matrix1

def matrix_counting(matrix):
    matrix_list = [matrix]
    for i in range(1,len(matrix)+1):
        result = np.linalg.matrix_power(matrix, i)
        matrix_list.append(result)
    for i in range(len(matrix_list)-1):
        matrix = matrix_sum(matrix_list[i], matrix_list[i+1])
    return  matrix

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=' ')
        print()

def check_connectivity(matrix):
    arr_list = [[] for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            arr_list[i].append(matrix[i][j])
    return arr_list

def check_row_equality(matrix, row1_index, row2_index):
    if row1_index < 0 or row1_index >= len(matrix) or row2_index < 0 or row2_index >= len(matrix):
        return False

    return matrix[row1_index] == matrix[row2_index]

def check_list(matrix):
    list_of_rows = []
    for i in range(len(matrix)):
        for j in range(i,len(matrix)):
            flag = check_row_equality(matrix, i,j)
            if flag == 1:
                list_of_rows.append(matrix[i])
    return list_of_rows

def point_print(arr):
    fake_arr = arr
    for i in range(len(arr)):
        for j in range(len(arr)):
            if fake_arr[i] == fake_arr[j]:
                fake_arr.pop(i)
    return fake_arr

def print_list(arr):
    for i in range(len(arr)):
        print(arr[i], end="\n")

def clean_list(arr):
    return np.unique(arr, axis=0)

def print_points(matrix):
    for row_index, row in enumerate(matrix):  # Используем enumerator для получения индекса строки
        indices = [index+1 for index, value in enumerate(row) if value == 1]  # Находим индексы единиц
        if indices:  # Проверяем, есть ли индексы для вывода
            print(f"Компонент связности {row_index+1}: {', '.join(map(str, indices))}")
        else:
            print(f"Нет компонент связности {row_index}")



def main():
    matrix = read_matrix_from_file("Matrix Graph/Matrix4")
    matrix = matrix_counting(matrix)
    matrix = matrix_downgrade(matrix)
    print_matrix(matrix)
    print("-----")
    middle_list = (check_list(check_connectivity(matrix)))
    middle_list.sort()
    middle_list = clean_list(middle_list)
    print_list(middle_list)
    print_points(middle_list)


if __name__ == "__main__":
    main()