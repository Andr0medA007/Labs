import itertools

def get_sdnf_from_terms(minterms, num_vars):
    expressions = []
    for minterm in minterms:
        expr = []
        for i in range(num_vars):
            if minterm & (1 << i):
                expr.append(chr(65 + i))
            else:
                expr.append(f'-{chr(65 + i)}')
        expressions.append(''.join(expr))
    return ' v '.join(expressions)

def get_groups(minterms, num_vars):
        groups = [[] for _ in range(num_vars + 1)]
        for minterm in minterms:
            ones_count = bin(minterm).count('1')
            groups[ones_count].append(minterm)
        return groups

def simplify_sdnf(truth_table):
    num_vars = len(bin(len(truth_table) - 1)[2:])
    minterms = [i for i, value in enumerate(truth_table) if value == 1]

    groups = get_groups(minterms, num_vars)
    new_groups = []
    for i in range(num_vars):
        for t1 in groups[i]:
            for t2 in groups[i + 1]:
                combined = combine_terms(t1, t2, num_vars)
                if combined is not None:
                    if combined not in new_groups:
                        new_groups.append(combined)


    simplified_sdnf = get_sdnf_from_terms(new_groups, num_vars)
    return simplified_sdnf

def combine_terms(term1, term2, num_vars):
    diff_bits = [i for i in range(num_vars) if (term1 >> i & 1) != (term2 >> i & 1)]
    if len(diff_bits) == 1:
        new_term = term1 & ~(1 << diff_bits[0])
        return new_term
    return None

def main():
    arr = [0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0]
    simplified_mdnf = simplify_sdnf(arr)
    print(simplified_mdnf)

if __name__ == "__main__":
    main()