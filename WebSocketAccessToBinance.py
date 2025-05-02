import websocket
import json

message_count = 0
entries_to_download = 5
def on_message(ws, mes):
    global message_count
    message_count += 1
    # Parse and handle incoming messages
    data = json.loads(mes)
    parsedData = extract_depth_update(data)
    print(f"Stream Data: {parsedData}")
    formatedData = replace_single_with_double_quotes(str(parsedData))
    with open("ResourceFiles/binance_stream_output.txt", "a") as file:
        file.write(formatedData)
        file.write("\n")
        
    if message_count >= entries_to_download:
        print("Received 5 messages. Closing connection...")
        ws.close()
        file.close()

def on_error(ws, error):
    print(f"Error: {error}")
    ws.close()

def on_close(ws, close_status_code, close_msg):
    print("Stream closed")

def on_open(ws):
    print("Stream opened")
import json

def extract_depth_update(data):
    try:
        # Extract relevant fields
        depth_update = {
            "e": data.get("e"),
            "E": data.get("E"),
            "s": data.get("s"),
            "b": data.get("b"),
            "a": data.get("a")
        }
        return depth_update
    except json.JSONDecodeError:
        print("Error: Invalid JSON data.")
        return None
    
def replace_single_with_double_quotes(input_string):
    """
    Replaces all single quotes with double quotes in the input string.
    """
    return input_string.replace("'", '"')

# Example WebSocket message (as a JSON string)


# Stream URL for BTC/USDT Depth Stream
stream_url = "wss://stream.binance.com:9443/ws/btcusdt@depth"

# Create WebSocket connection
ws = websocket.WebSocketApp(
    stream_url,
    on_message=on_message,
    on_error=on_error,
    on_close=on_close,
    on_open=on_open
)

# Run the WebSocket client
ws.run_forever()
