def nextLetter(rank, str):
    ch = 97
    temp = 0
    while rank > temp:
        if chr(ch) not in str:
            temp += 1
        ch += 1

    return chr(ch - 1)


def recursion(rank, length_of_chars, prev_solution=""):
    if length_of_chars == 1:
        final_solution = prev_solution + nextLetter(rank, prev_solution)
        return final_solution

    combinations = 1
    t = 25 - len(prev_solution)
    for i in range(length_of_chars - 1):
        combinations *= t
        t -= 1

    curr_pos = 0
    while rank > combinations:
        curr_pos += 1
        rank -= combinations

    curr_solution = prev_solution + nextLetter(curr_pos + 1, prev_solution)

    final_solution = recursion(rank, length_of_chars - 1 , curr_solution)

    return final_solution


rank = int(input())
length_of_chars = int(input())

solution = recursion(rank, length_of_chars)
print(solution, end="")
