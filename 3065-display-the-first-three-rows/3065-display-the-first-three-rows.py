import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    ans = pd.DataFrame(employees).head(3)
    return ans