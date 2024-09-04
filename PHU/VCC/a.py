import pandas as pd

df = pd.read_parquet('train-00000-of-00001.parquet', engine='pyarrow')
print(df.head())

print(df.iloc[0]['text'])
print(df.iloc[0]['gen'])