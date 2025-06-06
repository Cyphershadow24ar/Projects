def code_madlib():
    template = """
    I love computer programming because it's [Adjective1]! The journey to becoming a
    good programmer starts with hope in your mind and a dream in your [Body Part]. Through blood,
    sweat, and [Plural Noun1], hopefully it never ends. Yes, once you learn to [Verb], it becomes
    a part of your life identity and you can become a super [Adjective2] hacker. Knowledge of programming
    lets you take control of your [Noun1]. You can create your own personal [Plural Noun2], anything
    from developing [Adjective3] software to analyzing data and making predictions about the [Noun2].
    You can maybe even recreate Jarvis and make him extra [Adjective4]. I hope you'll start your
    [Adjective5] journey by coding with Kylie :)
    """
    print("Here’s the story you’re going to fill in:\n")
    print(template)

    body_part = input("Body Part: ")
    verb = input("Verb: ")
    adj1 = input("Adjective: ")
    adj2 = input("Adjective: ")
    adj3 = input("Adjective: ")
    adj4 = input("Adjective: ")
    adj5 = input("Adjective: ")
    noun1 = input("Noun: ")
    noun2 = input("Noun: ")
    noun_plural_1 = input("Noun (plural): ")
    noun_plural_2 = input("Noun (plural): ")

    madlib = f"""
    I love computer programming because it's {adj1}! The journey to becoming a
    good programmer starts with hope in your mind and a dream in your {body_part}. Through blood,
    sweat, and {noun_plural_1}, hopefully it never ends. Yes, once you learn to {verb}, it becomes
    a part of your life identity and you can become a super {adj2} hacker. Knowledge of programming
    lets you take control of your {noun1}. You can create your own personal {noun_plural_2}, anything
    from developing {adj3} software to analyzing data and making predictions about the {noun2}.
    You can maybe even recreate Jarvis and make him extra {adj4}. I hope you'll start your
    {adj5} journey by coding with Kylie :)
    """
    print("\nHere’s your Madlib:\n")
    print(madlib)