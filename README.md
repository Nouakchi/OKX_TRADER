---
title: "OKX CLI Trader"
description: "A Command-Line Interface (CLI) application for managing orders on OKX, coded in C++ and requiring the libcurl library."
---

# OKX CLI Trader

A Command-Line Interface (CLI) application for managing orders on OKX, coded in C++ and requiring the libcurl library. This tool allows users to efficiently handle their trading activities directly from the terminal.

## Features

- **Order Management**: Create, cancel, and view orders.
- **Market Data**: Fetch and display current market data.
- **Account Information**: View account balances and trading history.
- **Trading Pairs**: Support for multiple trading pairs.
- **Security**: Securely manage API keys.

## Prerequisites

- C++ compiler (e.g., g++)
- [libcurl](https://curl.se/libcurl/)
- OpenSSL libraries

## Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/username/okx-cli-trader.git
    cd okx-cli-trader
    ```

2. **Install dependencies**:
    On Debian-based systems, you can install the required libraries using:
    ```sh
    sudo apt-get install libcurl4-openssl-dev libssl-dev
    ```

3. **Set up your environment**:
    Create a `.env` file in the project root with your OKX API credentials:
    ```sh
    OKX_API_KEY=your_api_key
    OKX_API_SECRET=your_api_secret
    OKX_PASS_PHRASE=your_passphrase
    ```

## Building the Project

1. **Build the project**:
    ```sh
    make all
    ```

2. **Clean the build**:
    ```sh
    make clean
    ```

3. **Rebuild the project**:
    ```sh
    make re
    ```
4. **Help**
   ```sh
   make help
   ```

## Usage

1. **Run the CLI**:
    ```sh
    ./goQuant_trader
    ```

2. **Available Commands**:
    - `create_order`: Create a new order.
    - `cancel_order`: Cancel an existing order.
    - `view_orders`: View open and closed orders.
    - `market_data`: Get current market data.
    - `account_info`: Display account information.

## Contributing

1. **Fork the repository**.
2. **Create a new branch**:
    ```sh
    git checkout -b feature/your-feature
    ```
3. **Commit your changes**:
    ```sh
    git commit -m 'Add some feature'
    ```
4. **Push to the branch**:
    ```sh
    git push origin feature/your-feature
    ```
5. **Open a pull request**.

## Contact

For any inquiries or issues, please contact Othmane Nouakchi at Othman.nouakchi007@gmail.com.
