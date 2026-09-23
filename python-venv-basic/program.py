import sys


def parse_integer(value: str) -> int | None:
    if value.startswith(("+", "-")):
        digits = value[1:]
    else:
        digits = value

    if digits == "" or not digits.isdigit():
        return None

    return int(value)


def main(argv: list[str] | None = None) -> int:
    args = sys.argv[1:] if argv is None else argv
    total = 0

    for arg in args:
        value = parse_integer(arg)

        if value is None:
            print(f"Invalid integer: {arg}", file=sys.stderr)
            return 1

        total += value

    print(f"Sum: {total}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
