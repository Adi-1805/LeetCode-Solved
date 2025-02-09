import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    required_order = animals[animals['weight'] > 100].sort_values(by='weight', ascending=False)
    return required_order[['name']]