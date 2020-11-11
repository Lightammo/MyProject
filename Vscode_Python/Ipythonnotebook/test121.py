import helper
import random
env_data = helper.fetch_maze()
rows = len(env_data)

#TODO 2模拟环境的列数
columns = len(env_data[0])

loc_map = {'start':list((i,env_data[i].index(1)) for i in range(len(env_data)) if 1 in env_data[i])[0],'destination':list((i,env_data[i].index(3)) for i in range(len(env_data)) if 3 in env_data[i])[0]}  
#TODO 6按照上述要求创建字典
robot_current_loc = None
robot_current_loc = loc_map['start'] #TODO 7保存机器人当前的位置


actionorder={'u':(-1,0),'d':(1,0),'l':(0,-1),'r':(0,1)}

def Jagde_legal(loc):
    if 0 <= loc[0] < rows and 0 <= loc[1] < columns and env_data[loc[0]][loc[1]] != 2:
        return True
    return False

def move_robot(loc,act):
    next_loc = tuple(map(sum, zip(loc,actionorder[act])))
    return next_loc

def is_move_valid_special(loc, act):
    next_loc = move_robot(loc, act)
    if Jagde_legal(next_loc):
        return True
    return False


def valid_actions(env_data,loc):
    actlist = []
    for x in actionorder:
        if is_move_valid_special(loc,x):
            actlist.append(x)
    return actlist


def DFS(env_data,loc):
    global robot_current_loc
    print(robot_current_loc)
    if env_data[loc[0]][loc[1]] != 3:
        env_data[loc[0]][loc[1]] = 2
        actlib = valid_actions(env_data,loc)
        robot_current_loc = next_loc = move_robot(loc,actlib[0])
        DFS(env_data,next_loc)
    else:
        pass

DFS(env_data,robot_current_loc)