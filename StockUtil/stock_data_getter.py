import yfinance as yf
import json
import sys

if len(sys.argv) != 2:
    print("Usage: stock_data_getter.py <Ticker>")
    exit(-1)

ticker = sys.argv[1]
stock = yf.Ticker(ticker)

print(json.dumps(stock.get_info(), indent=4))