class DFA:
    def __init__(self):
        self.current_state = 'q0'
        self.accept_states = {'q1'}

        # Таблица переходов
        self.transitions = {
            'q0': {'a': 'q0', 'b': 'q0', 'c': 'q1', 'd': 'q0'},
            'q1': {'a': 'q0', 'b': 'q0', 'c': 'q2', 'd': 'q0'},
            'q2': {'a': 'q0', 'b': 'q0', 'c': 'q1', 'd': 'q0'}
        }

    def process_input(self, input_string):
        """Обрабатывает входную строку и возвращает, принимает ли её автомат."""
        self.current_state = 'q0'  # Переход в начальное состояние

        for char in input_string:
            if char not in {'a', 'b', 'c', 'd'}:
                raise ValueError(f"Недопустимый символ в алфавите: '{char}'")
            self.current_state = self.transitions[self.current_state][char]
        return self.current_state in self.accept_states
if __name__ == "__main__":
    dfa = DFA()
    test_words = ["132acc", "avbccc", "aabccccc", "abcc", "cc", "abccc", "abcd",""]

    for word in test_words:
        try:
            if len(word) == 0:
                print(f"Слово '{word}': {'принимается'}")
            else:
                accepted = dfa.process_input(word)
                print(f"Слово '{word}': {'принимается' if accepted else 'не принимается'}")
        except ValueError as e:
            print(f"Ошибка в слове '{word}': {e}")