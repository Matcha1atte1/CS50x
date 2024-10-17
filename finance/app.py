import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session.get('user_id')
    if not user_id:
        return redirect("/login")

    # query to get stocks owned by user
    user_stocks = db.execute("SELECT )
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        # check for blank symbol
        if not symbol:
            return apology("Invalid symbol")
        # check for valid symbol via lookup
        quoted_data = lookup(symbol)

        if quoted_data is None:
            return apology("Invalid Symbol")
        # check if shares is a positive integer
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("Invalid number of shares")
        except ValueError:
                return apology("Shares must be a positive integer")

        # retrieve user's cash balance
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        # calculate the total cost
        total_cost = shares * quoted_data["price"]

        # check if user can afford shares at the current stock price

        if user_cash < total_cost:
            return apology("Insufficient cash")
        else:
            # record the purchase
            db.execute("INSERT INTO purchases (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", user_id, symbol, shares, quoted_data["price"])

            # update the cash balance of the user
            db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, user_id)

            # redirect to home page upon completion
            return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")

    if request.method == "POST":
        symbol = request.form.get("symbol")

        # symbol not empty
        if not symbol:
            return apology("Symbol required")

        quoted_data = lookup(symbol)

        if quoted_data is None:
            return apology("Invalid Symbol")

        return render_template("quoted.html", quoted=quoted_data, usd=usd)

    return apology("Invalid request")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        # check for empty fields
        if not username or not password or not confirmation:
            return apology("All fields are required")
        # check for matching passwords
        if password != confirmation:
            return apology("Passwords do not match")
        # hash password
        hash_password = generate_password_hash(password)

        # insert user into users
        try:
            db.execute("INSERT into users (username, hash) VALUES (?, ?)", username, hash_password)
        # except when there is duplicate username
        except ValueError:
            return apology("Username already exists")


        return redirect("/login")

    return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
