def read_matrix_from_file(filename):
    matrix = []
    with open(filename, 'r') as file:
        for line in file:
            row = list(map(int, line.split()))
            matrix.append(row)
    for i in range(len(matrix)):
        matrix[i][i] = 1
    return matrix

def create_pairs(matrix):
    list_of_pairs = []
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] != 0 and j>i:
                list_of_pairs.append([matrix[i][j],i+1,j+1])
    return list(list_of_pairs)

def kraskal_func(Rs):
    U = set()  # список соединенных вершин
    D = {}  # словарь списка изолированных групп вершин
    T = []  # список ребер остова

    for r in Rs:
        if r[1] not in U or r[2] not in U:  # проверка для исключения циклов в остове
            if r[1] not in U and r[2] not in U:  # если обе вершины не соединены, то
                D[r[1]] = [r[1], r[2]]  # формируем в словаре ключ с номерами вершин
                D[r[2]] = D[r[1]]  # и связываем их с одним и тем же списком вершин
            else:  # иначе
                if not D.get(r[1]):  # если в словаре нет первой вершины, то
                    D[r[2]].append(r[1])  # добавляем в список первую вершину
                    D[r[1]] = D[r[2]]  # и добавляем ключ с номером первой вершины
                else:
                    D[r[1]].append(r[2])  # иначе, все то же самое делаем со второй вершиной
                    D[r[2]] = D[r[1]]

            T.append(r)  # добавляем ребро в остов
            U.add(r[1])  # добавляем вершины в множество U
            U.add(r[2])

    for r in Rs:  # проходим по ребрам второй раз и объединяем разрозненные группы вершин
        if r[2] not in D[r[1]]:  # если вершины принадлежат разным группам, то объединяем
            T.append(r)  # добавляем ребро в остов
            gr1 = D[r[1]]
            D[r[1]] += D[r[2]]  # объединяем списки двух групп вершин
            D[r[2]] += gr1
    return T

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=' ')
        print()

def sym_matrix(matrix):
    sum_mat = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            sum_mat += matrix[i][j]
    print(sum_mat)

def main():
    file_name = "Matrix_Mass/g22.txt"
    zero_matrix = [[0 for _ in range(10)] for _ in range(10)]
    matrix = read_matrix_from_file(file_name)
    if file_name == "Matrix_Mass/g22.txt":
        list_of_pairs = create_pairs(matrix)
        print(list_of_pairs)

        list_of_pairs.sort(key=lambda x: x[0])
        print(list_of_pairs)
        kraskal_list = kraskal_func(list_of_pairs)

        for point in kraskal_list:
            zero_matrix[point[1] - 1][point[2] - 1] = point[
                0]  # первое число - значение, второе - координата x, третие - координата y
        print_matrix(zero_matrix)
        print(18)
    else:

        list_of_pairs = create_pairs(matrix)
        print(list_of_pairs)

        list_of_pairs.sort(key = lambda x: x[0])
        print(list_of_pairs)
        kraskal_list = kraskal_func(list_of_pairs)

        for point in kraskal_list:
            zero_matrix[point[1]-1][point[2]-1] = point[0] # первое число - значение, второе - координата x, третие - координата y
        print_matrix(zero_matrix)
        sym_matrix(zero_matrix) # 25 18 25 31

if __name__ == "__main__":
    main()
