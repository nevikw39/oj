records = []  # YOUR CODE to initialize the data structure
total = 0


def write_record(expense: int, date="2020/01/18", description="something") -> None:  # YOUR PARAMETERS
    # YOUR CODE to write to records
    records.append("${}, {}, {}".format(expense, date, description))
    global total
    total += expense


def list_records() -> None:
    # YOUR CODE to print the records
    print('\n'.join(records))


def total_expense() -> int:
    # YOUR CODE to return the total expense
    return total


for i in range(4):
    calling_write_record = input()
    exec(calling_write_record)
list_records()
print(total_expense())
