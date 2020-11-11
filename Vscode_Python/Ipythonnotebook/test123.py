import helper
import random
env_data = helper.fetch_maze()
actionorder={'u':(-1,0),'d':(1,0),'l':(0,-1),'r':(0,1)}

loc_map = {'start':tuple(list((i,env_data[i].index(1)) for i in range(len(env_data)) if 1 in env_data[i])),'destination':tuple(list((i,env_data[i].index(3)) for i in range(len(env_data)) if 3 in env_data[i]))}
for x in loc_map:
    print((loc_map[x]))
def is_move_valid_special(loc, act):
    next_loc = tuple(map(sum, zip(loc,actionorder[act])))
    if env_data[next_loc[0]-1][next_loc[1]-1] != 2 and 0<=next_loc[0]-1<len(env_data[0]) and 0<=next_loc[1]-1<len(env_data):
        return True
    return False    

def valid_actions(env_data,loc):
    actlist = []
    for x in actionorder:
        if is_move_valid_special(loc,x):
            actlist.append(x)
    return actlist

    
def move_robot(loc,act):
    next_loc = tuple(map(sum, zip(loc,actionorder[act])))
    return next_loc

#def random_choose_actions(env_data,loc):
#    actlist = valid_actions(env_data,loc)
#    random.chioce()


#if env_data[next_loc[0]-1][next_loc[1]-1] != 2 and 0<=next_loc[0]-1<len(env_data[0]) and 0<=next_loc[1]-1<len(env_data):
#       return True
 #   return False

 @#   robot_current_loc
    '''next_loc = tuple(map(sum, zip(loc,actionorder[art])))
    if env_data[next_loc[0]-1][next_loc[1]-1] == 2 or 0<=next_loc[0]-1<len(env_data[0]) or 0<=next_loc[1]-1<len(env_data):
        return True
    return False

actionorder={'u'}'''