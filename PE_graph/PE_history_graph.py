import pandas as pd
import matplotlib.pyplot as plt

columns = ["Date", "Problems"]
file_path = "/home/mathilde/GithubDesktop/Euler/PE_graph/history.csv"  # Update the file path to the correct location

df = pd.read_csv(
    file_path,
    usecols=[0, 1],
    header=None,
    names=columns,
)


# Convert date column to datetime and set to date only
df["Date"] = pd.to_datetime(
    df["Date"], format="%d %b %y (%H:%M)", errors="coerce"
).dt.date

# Fill missing dates with the minimum date
min_date = min(df["Date"])
df["Date"].fillna(min_date, inplace=True)

# Sort by date and group by date, then calculate cumulative and previous values
df = df.sort_values(by="Date")
df = df.groupby("Date").count().reset_index()
df["Cumulative"] = df["Problems"].cumsum()
df["Previous"] = df["Cumulative"] - df["Problems"]

# Create a copy of the DataFrame for cumulative values
cumsum = df[["Date", "Cumulative"]].copy()
cumsum.rename(columns={"Cumulative": "Problems Solved"}, inplace=True)

# Create a copy of the DataFrame for previous values
previous = df[["Date", "Previous"]].tail(-1).copy()
previous.rename(columns={"Previous": "Problems Solved"}, inplace=True)

# Concatenate cumulative and previous values
result = pd.concat([cumsum, previous])
result = result.sort_values(by=["Date", "Problems Solved"], ascending=True)

# Plot the data and save the figure
fig = result.plot(x="Date", y="Problems Solved").get_figure()
fig.savefig("PEgraph.jpg")