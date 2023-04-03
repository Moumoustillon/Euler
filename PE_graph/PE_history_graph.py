import pandas as pd
import matplotlib

columns = ["Date", "Problems"]
df = pd.read_csv(
    "history.csv",
    usecols=[0, 1],
    header=None,
    names=columns,
)

df["Date"] = pd.to_datetime(
    df["Date"], format="%d %b %y (%H:%M)", errors="coerce"
).dt.date

min_date = min(df["Date"])
df["Date"].fillna(min_date, inplace=True)
df = df.sort_values(by="Date")
df = df.groupby("Date").count().reset_index()
df["Cumulative"] = df["Problems"].cumsum()
df["Previous"] = df["Cumulative"] - df["Problems"]

cumsum = df[["Date", "Cumulative"]]
cumsum.rename(columns={"Cumulative": "Problems Solved"}, inplace=True)

previous = df[["Date", "Previous"]].tail(-1)
previous.rename(columns={"Previous": "Problems Solved"}, inplace=True)

result = pd.concat([cumsum, previous])
result = result.sort_values(by=["Date", "Problems Solved"], ascending=True)

fig = result.plot(x="Date", y="Problems Solved").get_figure()
fig.savefig("PEgraph.jpg")