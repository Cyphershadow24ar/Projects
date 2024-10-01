import re

def password_strength(password):
    """
    Evaluates the strength of a given password.

    Parameters:
    password (str): The password string to evaluate.

    Returns:
    str: Strength category of the password.
    """

    # Initialize score
    score = 0

    # Criteria patterns
    length_pattern = r'.{8,}'  # At least 8 characters
    lowercase_pattern = r'[a-z]'
    uppercase_pattern = r'[A-Z]'
    digit_pattern = r'\d'
    special_char_pattern = r'[\W_]'  # Non-alphanumeric characters
    # Common passwords list (for simplicity, a small sample)
    common_passwords = ['password', '123456', '123456789', 'qwerty', 'abc123']

    # Check for common passwords
    if password.lower() in common_passwords:
        return "Very Weak (Common Password)"

    # Length check
    if re.search(length_pattern, password):
        score += 1
    else:
        score += 0

    # Lowercase letters
    if re.search(lowercase_pattern, password):
        score += 1

    # Uppercase letters
    if re.search(uppercase_pattern, password):
        score += 1

    # Digits
    if re.search(digit_pattern, password):
        score += 1

    # Special characters
    if re.search(special_char_pattern, password):
        score += 1

    # Evaluate score
    if score == 0:
        return "Very Weak"
    elif score == 1:
        return "Weak"
    elif score == 2:
        return "Moderate"
    elif score == 3:
        return "Strong"
    elif score >= 4:
        return "Very Strong"

def main():
    print("=== Password Strength Analyzer ===")
    password = input("Enter a password to evaluate: ")
    strength = password_strength(password)
    print(f"Password Strength: {strength}")

if __name__ == "__main__":
    main()
