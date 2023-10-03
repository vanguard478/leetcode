import pandas as pd

# Load the first dataframe
df1 = pd.read_csv("/home/vanguard/dev/leetcode/utils/data.csv")

# Load the second dataframe
df2 = pd.read_csv("/home/vanguard/dev/leetcode/utils/data_clock.csv")
# 
# Rename the column in df2 to match the corresponding column in df1 for merging
# df2.rename(columns={'Product Name':'GeForce'}, inplace=True)

# Merge the dataframes on the GeForce column
# merged_df = pd.merge(df1, df2[['GeForce', 'Memory clock']], on='GeForce', how='left')

# Save the merged dataframe as a new CSV
# merged_df.to_csv('merged.csv', index=False)
"""
df1: Index(['card_name', 'NVIDIA CUDA Cores', 'Boost Clock (GHz)',
       'Base Clock (GHz)', 'Standard Memory Config', 'Memory Interface Width'],
      dtype='object')
      
df2: Index(['Product Name', 'GPU Chip', 'Released', 'Bus', 'Memory', 'GPU clock',
       'Memory clock', 'Shaders / TMUs / ROPs'],
      dtype='object')
      
"""
df2['Product Name'] = df2['Product Name'].str.replace('\xa0', ' ')
df2['Product Name'] = df2['Product Name'].str.replace('GeForce', '')
df2['Product Name'] = df2['Product Name'].str.strip()
df2['Product Name'] = df2['Product Name'].str.replace('\s+',' ')

df1['card_name'] = df1['card_name'].str.replace('GeForce','')
df1['card_name'] = df1['card_name'].str.strip()
df1['card_name'] = df1['card_name'].str.replace('\s+',' ')


cards_in_df1 = df1['card_name'].to_list()
cards_in_df2 = df2['Product Name'].to_list()
print(cards_in_df1)
print(cards_in_df2)
for card in cards_in_df1:
    if card in cards_in_df2:
        pass
        # print(card)
    else:
        print(f"{card} not in df2")