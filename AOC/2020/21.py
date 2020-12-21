from collections import defaultdict
from typing import NamedTuple, List, Dict, Set


class Food(NamedTuple):
    ingredients: List[str]
    allergens: List[str]


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.foods: List[Food] = list()
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self) -> None:
        with open('21.test') as f:
            self.parse(f.read())
        assert self.countSafeIngredients() == 5
        assert self.getUnsafeIngredients() == 'mxmxvkd,sqjhc,fvjkl'

    def parse(self, param: str) -> None:
        self.foods = list()
        for food in param.strip().split('\n'):
            ings, foods = food[:-1].split(' (contains ')
            ings_list = ings.split(' ')
            foods_list = foods.split(', ')
            self.foods.append(Food(ings_list, foods_list))

    def countSafeIngredients(self) -> int:
        allergen_to_ingredient = self.assignAllergens()
        return self.countUnassigned(allergen_to_ingredient)

    def assignAllergens(self) -> Dict[str, str]:
        allergen_to_ingredient: Dict[str, Set[str]] = dict()
        ingredient_to_allergen: Dict[str, Set[str]] = defaultdict(set)
        self.mapAllergenAndIngredient(allergen_to_ingredient, ingredient_to_allergen)
        # topo sort
        stack: List[str] = list()
        for allergen, ingredient_set in allergen_to_ingredient.items():
            canAssign = len(ingredient_set) == 1
            if canAssign:
                stack.append(allergen)
        while len(stack):
            u = stack.pop()
            assert len(allergen_to_ingredient[u]) == 1
            ingredient = next(iter(allergen_to_ingredient[u]))
            for v in ingredient_to_allergen[ingredient]:
                sameAllergen = v == u
                if sameAllergen:
                    continue
                vi = allergen_to_ingredient[v]
                vi.remove(ingredient)
                canAssign = len(vi) == 1
                if canAssign:
                    stack.append(v)
        ans: Dict[str, str] = dict()
        for allergen, ingredient_set in allergen_to_ingredient.items():
            assert len(ingredient_set) == 1
            ingredient = next(iter(ingredient_set))
            ans[allergen] = ingredient
        return ans

    def mapAllergenAndIngredient(self, allergen_to_ingredient: Dict[str, Set[str]], ingredient_to_allergen: Dict[str, Set[str]]):
        for food in self.foods:
            for allergen in food.allergens:
                ingredient_set = set(food.ingredients)
                if allergen not in allergen_to_ingredient:
                    allergen_to_ingredient[allergen] = ingredient_set
                else:
                    allergen_to_ingredient[allergen] &= ingredient_set
        for allergen, ingredient_set in allergen_to_ingredient.items():
            for ingredient in ingredient_set:
                ingredient_to_allergen[ingredient].add(allergen)

    def countUnassigned(self, allergen_to_ingredient: Dict[str, str]) -> int:
        cnt: int = 0
        assigned_ingrediens = set(allergen_to_ingredient.values())
        for food in self.foods:
            for ingredient in food.ingredients:
                if ingredient not in assigned_ingrediens:
                    cnt += 1
        return cnt

    def getUnsafeIngredients(self) -> str:
        allergen_to_ingredients = self.assignAllergens()
        sortByAllergen = lambda x: x[0]
        canonical_food = sorted(allergen_to_ingredients.items(), key=sortByAllergen)
        canonical_ingredients = (f[1] for f in canonical_food)
        return ','.join(canonical_ingredients)


s = Solution('21.in', True)
print(s.countSafeIngredients())
print(s.getUnsafeIngredients())
