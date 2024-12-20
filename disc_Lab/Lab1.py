import re
from random import *

universe = [i for i in range(-100,101)]

def get_left_right_indexes():
    r_size = 0
    l_size = 0
    while not (100 > r_size > 0):
        r_size = int(input("Введите правую границу множества: "))
        if not (100 > r_size > -99):
            print("Введите число из диапазона [-99, 100]")
    while not (99 > l_size > -100):
        l_size = int(input("Введите правую границу множества: "))
        if not (99 > l_size > -100):
            print("Введите число из диапазона [-100, 99]")
    return l_size, r_size

def strange_input():
    l_size, r_size = get_left_right_indexes()
    while l_size > r_size:
        print("Правая граница диапазона должна быть больше левой!")
        l_size, r_size = get_left_right_indexes()
    k = int(input("Процент деления для чисел множества: "))
    arr = []
    for i in range(l_size, r_size):
        if i % k == 0:
            arr.append(i)
    l_size,r_size = 0,0
    return arr
def hand_input():
    size = int(input("Введите размер множества: "))
    arr = []
    for i in range(size):
        x = int(input("Введите элемент множества: "))
        arr.append(x)
    return arr


def start_brackets_counter(input_string):
    count = 1
    for i in range(len(input_string)):
        if count != 1 and (input_string[i] == '(' or input_string[i] == '#'):
            count+=1
        if input_string[i] != '(':
                break
    return count

def get_index(input_string):
    i_l_bracket = 0
    i_r_bracket = 0
    for i in input_string:
        if i == '[':
            i_l_bracket = input_string.index('[')
            break
    for i in input_string:
        if i == ']':
            i_r_bracket = input_string.index(']')
            break
    return i_l_bracket,i_r_bracket

def find_bracket(final_string):
    l_index = 0
    r_index = 0
    for i in range(len(final_string)):
        if final_string[i] == '(':
            l_index = i
    for i in range(l_index, len(final_string)):
        if final_string[i] == ')' and final_string[i-1] == ')':
            r_index = i-1
            break
        elif final_string[i] == ')' and final_string[i-1] != ')':
            r_index = i
            break
    print(l_index,r_index)
    return l_index, r_index

def is_bracket(input_string):
    flag = 0
    for i in input_string:
        if i in ['(', ')']:
            flag = 1
            break
    if flag == 1:
        return 1
    else:
        return 0

def random_plenty():
    array_size = int(input("Введите длину множествa: "))
    lot_array = [randint(-100, 100) for i in range(array_size)]
    print(lot_array)
    return lot_array
def current_plenty():
    a_size = int(input("Введите длину множествa: "))
    lot_a = []
    for i in range(a_size):
        lot_a.append(int(input("Введите число: ")))
    return lot_a

def anti_plenty(lot_a):
    for k in lot_a:
        universe.pop(universe.index(k))
    return universe

def string_convert(input_string,lot_array):
    for smth in input_string:
        if smth in ['a','b','c','d','e','f','A','B','C','D','E','F']:
            input_string = input_string.replace(smth, ''.join(str(lot_array)))
            break
    return input_string

def find_result(string):
    while  'v' in string or '^' in string or '#' in string or '$' in string:
        if is_bracket(string):
            while is_bracket(string):
                stack = []
                let_string = ''
                l_index, r_index = find_bracket(string)
                final_string = string[l_index+1:r_index]
                cur_string = final_string
                i_left_bracket, i_right_bracket = get_index(final_string)
                while len(final_string) >2:
                    cnt = start_brackets_counter(string)
                    nums = re.findall(r'[-+]?\d+',final_string[i_left_bracket:i_right_bracket])
                    nums = [int(i) for i in nums]
                    stack.append(nums)
                    final_string = final_string[i_right_bracket+2: len(final_string)]
                for i in cur_string:
                    if i in ['v','^','#','$']:
                        let_string = let_string + i
                stack.reverse()
                for i in let_string:
                    if i == 'v':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1) | set(arr2)))
                    if i == '^':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1) & set(arr2)))
                    if i == '#':
                        arr1 = stack.pop()
                        stack.append(list(set(anti_plenty(arr1))))
                    if i == '$':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1) - set(arr2)))
                if l_index != 0:
                    string = string[0:l_index] + str(stack[0]) + string[r_index:-1]
                else:
                    string = string[:l_index] + str(stack[0]) + string[r_index+1:]
        elif 'v' in string or '^' in string or '#' in string or '$' in string:
            stack = []
            while len(stack) != 1:
                let_string = ''
                fin_string = string
                l_index, r_index = 0, len(string)
                i_left_bracket, i_right_bracket = get_index(string)
                while len(string) > 2:
                    cnt = start_brackets_counter(string)
                    nums = re.findall(r'[-+]?\d+', string[i_left_bracket:i_right_bracket])
                    nums = [int(i) for i in nums]
                    stack.append(nums)
                    string = string[i_right_bracket + 2: len(string)]
                for i in fin_string:
                    if i in ['v', '^','#','$']:
                        let_string = let_string + i
                stack.reverse()
                for i in let_string:
                    if i == 'v':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1) | set(arr2)))
                    if i == '^':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1) & set(arr2)))
                    if i == '$':
                        arr1 = stack.pop()
                        arr2 = stack.pop()
                        stack.append(list(set(arr1).difference(set(arr2))))
                if l_index != 0:
                    string = string[0:l_index] + str(stack[0]) + string[r_index:-0]
                else:
                    string = string[:l_index] + str(stack[0]) + string[r_index + 1:]
    return stack

def main():
    this_string = str(input("Введите строку действий(^ - пересечение, v - объединеение, # - отрицание, $ - разность: "))
    flag = 0
    while flag != 5:
        input_string = this_string
        flag = int(input("Действие:\n"
                         "1: Заполнение множества случайными числами\n"
                         "2: Заполнение множества числами от пользователя\n"
                         "3: Заполнение множества числами с процентом от деления на заданное число\n"
                         "4: Перезаписать строку\n"
                         "5: Выйти из программы\n"))
        match flag:
            case 1:
                val_count = 0
                vals = set()
                for i in input_string:
                    if i in ['a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F']:
                        vals.add(i)
                        val_count = len(vals)
                for i in range(0, val_count):
                    input_string = string_convert(input_string, random_plenty())
                stack = find_result(input_string)
                print("Результат: ",stack[0])
                stack = []
            case 2:
                val_count = 0
                vals = set()
                for i in input_string:
                    if i in ['a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F']:
                        vals.add(i)
                        val_count = len(vals)
                for i in range(0, val_count):
                    input_string = string_convert(input_string, current_plenty())
                stack = find_result(input_string)
                print("Результат: ", stack[0])
                stack = []
            case 3:
                val_count = 0
                vals = set()
                for i in input_string:
                    if i in ['a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F']:
                        vals.add(i)
                        val_count = len(vals)
                for i in range(0, val_count):
                    input_string = string_convert(input_string, strange_input())
                stack = find_result(input_string)
                print("Результат: ", stack[0])
                stack = []
            case 4:
                this_string = str(input("Введите строку действий(^ - пересечение, v - объединеение, # - отрицание, $ - разность: "))
            case 5:
                break

if __name__ == "__main__":
    main()
