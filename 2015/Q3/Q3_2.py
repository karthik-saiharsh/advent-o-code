def verify_unique(pos, visited):
    return pos in visited

def update_current_pos(current, c):
    match c:
        case '^':
            current[1] += 1
        case 'v':
            current[1] -= 1
        case '>':
            current[0] += 1
        case '<':
            current[0] -= 1

with open("input.txt", "r") as f:
    data = f.readline()
    
    current_santa = [0, 0]
    current_robo = [0, 0]
    houses_visited = 1

    visited = set({})
    visited.add("0,0")

    for i in range(0, len(data),2):
        santa_c = data[i]
        robo_santa_c = data[i+1]

        update_current_pos(current_santa, santa_c)
        update_current_pos(current_robo, robo_santa_c)

        santa_new = ','.join(str(x) for x in current_santa)
        robo_santa_new = ','.join(str(x) for x in current_robo)

        if not santa_new in visited:
            houses_visited+=1
            visited.add(santa_new)
        
        if not robo_santa_new in visited:
            houses_visited += 1
            visited.add(robo_santa_new)

    print(houses_visited)

