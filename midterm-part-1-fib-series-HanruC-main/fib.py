from enum import Enum
from typing import List
from functools import lru_cache
import click
import sys

sys.setrecursionlimit(100000)


class FibType(Enum):
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0


def fib_iterative(n: int) -> int:
    """
    Calculates the Fibonacci iteratively
    """

    fib_total = 0
    fib1 = 0
    fib2 = 1
    for i in range(n):
        fib_total = fib1 + fib2
        fib1 = fib2
        fib2 = fib_total
    return fib1


def fib_recursive(n: int) -> List[int]:
    """
    Calculates the Fibonacci recursively
    """

    if n == 0:
        return [0]
    elif n == 1:
        return [0, 1]
    else:
        fib_list = fib_recursive(n - 1)
        fib_list.append(fib_list[-1] + fib_list[-2])
        return fib_list


@lru_cache(maxsize=None)
def fib_dp(n: int) -> List[int]:
    """
    Calculate Fibonacci using dynamic programming.
    """
    fib_table = [-1] * (n + 1)
    fib_table[0] = 0
    fib_table[1] = 1
    for i in range(2, n + 1):
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2]
    return fib_table[:n + 1]


def get_fib(n: int, version: FibType) -> List[int]:
    """
    Version different from each algo
    """
    if version == FibType.ITERATIVE:
        return [fib_iterative(i) for i in range(1, n + 1)]
    elif version == FibType.RECURSIVE:
        return fib_recursive(n)
    elif version == FibType.DP:
        fib_list = []
        for i in range(1, n + 1):
            fib_list.append(fib_dp(i)[i - 1])
        return fib_list


def print_fib(n: int, print_it: bool = False, version: FibType = FibType.ITERATIVE) -> List[int]:
    if version == FibType.RECURSIVE:
        return fib_recursive(n)
    if version == FibType.DP:
        return fib_dp(n)
    fib_list = []
    for i in range(n):
        fib_list.append(fib_iterative(i))
        if print_it:
            print(fib_list[-1], end='')
    if print_it:
        print()
    return fib_list


@click.command()
@click.argument("n", type=click.IntRange(min=0, max=50000, clamp=True))
@click.option("--algo", type=click.Choice(['recursive', 'dp', 'iterative'], case_sensitive=False), default='iterative')
@click.option("--print-type", type=click.Choice(['all', 'none', 'single'], case_sensitive=False), default='none')
def main(n: int, algo: str, print_type: str):
    """
    Prints the nth Fibonacci number using the specified algorithm.

    Args:
        n: The number n for which the nth Fibonacci number.
        algo: The algorithm to be used.
        print_type: The type of output to be printed. Can be one of {'all', 'none', 'single'}. Defaults to 'none'.
    """
    print_it = print_type == 'all'
    t = FibType.ITERATIVE
    if algo == 'recursive':
        t = FibType.RECURSIVE
    elif algo == 'dp':
        t = FibType.DP
    fib_nums = get_fib(n, t)
    if print_type == 'single':
        print(fib_nums[-1])


if __name__ == "__main__":
    main()

