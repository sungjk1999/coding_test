# N = int(input())
# mat = []
# for _ in range(N):
#     line = list(map(int, input().split()))
#     mat.append(line)

N = 7
mat = [
    [0, 0, 1, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [1, 1, 0, 1, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0]
]

core = []
for i in range(1, N-1):
    for j in range(1, N-1):
        if mat[i][j] == 1:
            core.append((i, j))

res = []
init_ban = set()
for i in range(N):
    for j in range(N):
        if mat[i][j] == 1:
            init_ban.add((i, j))


def up_connect(i, j, banned):
    for u in range(i):
        if (u, j) in banned:
            return 0, banned
    new = banned.copy()
    for u in range(i):
        new.add((u, j))
    return i, new


def down_connect(i, j, banned):
    for u in range(i+1, N):
        if (u, j) in banned:
            return 0, banned
    new = banned.copy()
    for u in range(i+1, N):
        new.add((u, j))
    return N-1-i, new


def left_connect(i, j, banned):
    for u in range(j):
        if (i, u) in banned:
            return 0, banned
    new = banned.copy()
    for u in range(j):
        new.add((i, u))
    return j, new


def right_connect(i, j, banned):
    for u in range(j+1, N):
        if (i, u) in banned:
            return 0, banned
    new = banned.copy()
    for u in range(j+1, N):
        new.add((i, u))
    return N-1-j, new    


def dfs(core_idx, connected, dist, banned):
    if core_idx == len(core):
        res.append((connected, dist))
        return

    for direct in range(0, 5):
        i, j = core[core_idx]
        if direct == 0:  # Not connect
            dfs(core_idx+1, connected, dist, banned)
            
        elif direct == 1:  # Up
            offset, new = up_connect(i,j, banned)
            if offset > 0:
                dfs(core_idx+1, connected+1, dist+offset, new)
            else:
                dfs(core_idx+1, connected, dist, banned)

        elif direct == 2:  # Down
            offset, new = down_connect(i,j, banned)
            if offset > 0:
                dfs(core_idx+1, connected+1, dist+offset, new)
            else:
                dfs(core_idx+1, connected, dist, banned)

        elif direct == 3:  # Left
            offset, new = left_connect(i,j, banned)
            if offset > 0:
                dfs(core_idx+1, connected+1, dist+offset, new)
            else:
                dfs(core_idx+1, connected, dist, banned)

        elif direct == 4:  # Right
            offset, new = right_connect(i,j, banned)
            if offset > 0:
                dfs(core_idx+1, connected+1, dist+offset, new)
            else:
                dfs(core_idx+1, connected, dist, banned)


dfs(0,0,0,init_ban)
res.sort(key=lambda x: (-x[0], x[1]))
test_case = 1
print(f"#{test_case} {res[0][1]}")