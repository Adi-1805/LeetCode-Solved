import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    name = students.at[students[students['student_id'] == 101].index[0], 'name']
    age = students.at[students[students['student_id'] == 101].index[0], 'age']
    return pd.DataFrame({'name': [name], 'age': [age]})