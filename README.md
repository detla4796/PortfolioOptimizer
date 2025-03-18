# Portfolio Optimizer

A C++ program that helps select investments based on risk, income, and budget constraints.

## Description

This program implements a simple portfolio optimization strategy that selects investments by maximizing the income-to-risk ratio while staying within specified risk and budget limits.

## How It Works

1. The program takes user input for:
   - Maximum acceptable risk
   - Maximum budget
   - Number of investments to consider

2. For each investment, users enter:
   - Name of the investment
   - Expected income
   - Risk level
   - Price

3. The algorithm then:
   - Sorts investments by their income-to-risk ratio (higher ratios first)
   - Selects investments that fit within the maximum risk and budget constraints
   - Returns a list of selected investments
