import re
import math
from environments.environment_abstract import Environment


def get_environment(env_name: str) -> Environment:
    env_name = env_name.lower()
    env: Environment

    if env_name == 'cube3':
        from environment.cube3 import Cube3
        env = Cube3()
    else:
        raise ValueError('No known environment %s' % env_name)

    return env