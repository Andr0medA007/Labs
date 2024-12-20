class Function:
    def __init__(self, vector):
        self.vector = vector
        self.is_zero_keeping = self.zero_keeping_check()
        self.is_one_keeping = self.one_keeping_check()
        self.is_self_dual = self.self_dual_check()
        self.is_monotonous = self.monotonous_check()
        self.is_linear = self.linear_check()

    def zero_keeping_check(self):
        return self.vector[0] == '0'

    def one_keeping_check(self):
        return self.vector[-1] == '1'

    def self_dual_check(self):
        n = len(self.vector)
        for i in range(n // 2):
            if self.vector[i] == self.vector[n - 1 - i]:
                return False
        return True

    def monotonous_check(self):
        for i in range(len(self.vector) - 1):
            if self.vector[i] > self.vector[i + 1]:
                return False
        return True

    def show(self):
        text = " "
        text += "+ " if self.is_zero_keeping else "  "
        text += "+ " if self.is_one_keeping else "  "
        text += "+ " if self.is_self_dual else "  "
        text += "+ " if self.is_monotonous else "  "
        text += "+ " if self.is_linear else "  "
        print(text)

    def linear_check(self):
        if len(self.vector) != 8:
            raise ValueError("Длина вектора должна быть равной 8.")

        ones_count = self.vector.count('1')

        return ones_count in (0, 8) or ones_count % 2 == 0


def main():
    amount = int(input("Введите количество функций: "))
    functions_list = []

    for _ in range(amount):
        vector = input("Введите вектор функции: ")
        functions_list.append(Function(vector))

    print("   0 1 S M L")
    for i, func in enumerate(functions_list):
        print(f"f{i}", end="")
        func.show()


if __name__ == "__main__":
    main()