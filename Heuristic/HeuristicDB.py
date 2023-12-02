import Cube
import tqdm
import pickle

def stateAsString(state):
        return '\n\n'.join('\n'.join(' '.join(str(x or '----')for x in y)for y in z)for z in state)

def build_heuristic_db(goalState, commands, max_turn = 26):
    heuristic = {stateAsString(goalState): 0}
    que = [(goalState, 0)]
    node_count = sum([len(commands) ** (x + 1) for x in range(max_turn + 1)])
    with tqdm.tqdm(total = node_count, desc = 'Heuristic DB') as pbar:
        while True:
            if not que:
                break
            s, d = que.pop()
            if d > max_turn:
                continue
            cube = Cube.Cube(state = s)
            for command in commands:
                nextState = cube.turn(command)
                str = stateAsString(nextState)
                if str not in heuristic or heuristic[str] > d + 1:
                    heuristic[str] = d + 1
                que.append((nextState, d + 1))
                pbar.update(1)
    return heuristic

heuristic = build_heuristic_db(goalState = Cube.GOALSTATE, commands = Cube.COMMAND, max_turn = Cube.THRESHOLD)

with open('heuristic.pickle', 'wb') as fw:
    pickle.dump(heuristic, fw)