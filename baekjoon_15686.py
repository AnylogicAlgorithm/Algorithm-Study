from itertools import combinations

def calc_dist(chick_list, house_list):
    total_dist = 0
    for house in house_list:
        x1, y1 = house
        min_dist = 100000
        for chick in chick_list:
            x2, y2 = chick
            # print(x1, x2, y1, y2)
            dist = abs(x1 - x2) + abs(y1 - y2)
            if dist < min_dist:
                min_dist = dist
        total_dist += min_dist
    return total_dist

city = []
house_coord_list = []
chick_coord_list = []

n, m = input().split()
n = int(n)
m = int(m)
for i in range(n):
    line = input().split()
    for j in range(n):
        line[j] = int(line[j])
        if line[j] == 1:  # house
            house_coord_list.append((i, j))
        elif line[j] == 2:  # chicken
            chick_coord_list.append((i, j))
    city.append(line)

total_min_dist = 1000000
for i in range(1, m + 1):
    if i == 1:
        chick_combi = [[c] for c in chick_coord_list]
    else:
        chick_combi = list(combinations(chick_coord_list, i))
    # print(chick_combi)
    min_dist = 100000
    for idx, chick_comb in enumerate(chick_combi):
        dist = calc_dist(chick_comb, house_coord_list)
        # print(dist)
        if dist < min_dist:
            min_dist = dist
    if min_dist < total_min_dist:
        total_min_dist = min_dist
print(total_min_dist)

# print(n, m)
# print(city)
# print(house_coord_list)
# print(chick_coord_list)
# print(chick_combi)
