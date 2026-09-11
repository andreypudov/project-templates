function parseInteger(input: string): number | null {
  if (!/^-?\d+$/.test(input)) {
    return null;
  }
  return Number(input);
}

async function main(): Promise<void> {
  const args = process.argv.slice(2);
  let sum = 0;

  for (const arg of args) {
    const value = parseInteger(arg);

    if (value === null) {
      throw new Error(`Invalid integer: ${arg}`);
    }

    sum += value;
  }

  console.log(`Sum: ${sum}`);
}

main().catch((err: unknown) => {
  console.error(err instanceof Error ? err.message : err);
  process.exit(1);
});
