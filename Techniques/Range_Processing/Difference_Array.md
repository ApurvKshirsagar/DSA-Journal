# Technique: Difference Array

**Category:** Range Update Optimization (Constant Time and Linear Space)
**Goal:** Perform multiple range increment operations efficiently

---

## When Do We Use This?

Whenever a problem involves **multiple range updates** of the form:

```text
Add value v to all elements from index L to R
```

a naive approach takes **O(N)** per update, which is too slow when `N` and `Q` are large.

The **Difference Array Technique** reduces each update to **O(1)** time.

---

## Example

Let the array size be **10**, for simplicity, let all values be zeros initially.

We need to apply updates:

```text
(1, 4, 2)
(3, 8, 3)
```

Meaning:

- Add 2 to indices 1 through 4
- Add 3 to indices 3 through 8

---

## aive Method

For each update, iterate through the range →  
Time complexity: **O(N × Q)** in worst case.

---

## Difference Array Method

Instead of modifying every element in `[L, R]`, we maintain an auxiliary array:

```text
diff[] (size = n + 1)
```

I personally prefer using size **n + 1** to safely handle the `R + 1` position without boundary checks.

---

### Step 1 — Apply Updates

For `(1, 4, 2)`:

```text
diff[1] += 2
diff[5] -= 2
```

For `(3, 8, 3)`:

```text
diff[3] += 3
diff[9] -= 3
```

Now the diff array (1-indexed logic shown):

```text
[0, 2, 0, 3, 0, -2, 0, 0, 0, -3, 0]
```

---

### Step 2 — Reconstruct and Compute Sum

We maintain two variables:

- `cumulativeSum` → current array value
- `totalSum` → sum of all array elements

At each index:

```text
cumulativeSum += diff[i]
totalSum += cumulativeSum
```

---

### Dry Run

| i   | cumulativeSum | totalSum |
| --- | ------------- | -------- |
| 0   | 0             | 0        |
| 1   | 2             | 2        |
| 2   | 2             | 4        |
| 3   | 5             | 9        |
| 4   | 5             | 14       |
| 5   | 3             | 17       |
| 6   | 3             | 20       |
| 7   | 3             | 23       |
| 8   | 3             | 26       |
| 9   | 0             | 26       |
| 10  | 0             | 26       |

Final sum = **26**

---

## Verification

```text
4 elements × 2  = 8
6 elements × 3  = 18
Total = 26
```

Excatly matches the computed value.

---

## Why This Works

The difference array stores **boundary changes**.  
Prefix summation spreads these changes across the range.

Conceptually:

> Difference array = **discrete derivative**  
> Prefix sum = **integration**

---

## Complexity

| Operation         | Time         |
| ----------------- | ------------ |
| Each range update | **O(1)**     |
| Build final array | **O(N)**     |
| Total             | **O(N + Q)** |

---

## Common Mistakes

- Forgetting the `R + 1` position
- Mixing 0-index and 1-index logic
- Not rebuilding prefix sums

---

## Difference Array vs Segment Tree

| Scenario                                    | Better Choice        |
| ------------------------------------------- | -------------------- |
| Only range updates, final array needed once | **Difference Array** |
| Frequent queries after updates              | **Segment Tree**     |
| Online updates & queries                    | **Segment Tree**     |

Difference array is simpler and faster when applicable. Segment trees are more general but often **overkill** for pure range-update problems.

---

## Important Note

If operations include:

- Direct value assignment (`arr[i] = x`)
- Frequent sum queries after each update

Then a **Segment Tree with Lazy Propagation** is more appropriate.
