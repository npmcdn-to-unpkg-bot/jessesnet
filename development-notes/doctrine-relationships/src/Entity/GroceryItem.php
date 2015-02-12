<?php

namespace Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * GroceryItem
 *
 * @ORM\Table(name="grocery_item")
 * @ORM\Entity(repositoryClass="Entity\Repository\GroceryItem")
 */
class GroceryItem
{
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var integer
     *
     * @ORM\Column(name="food_group", type="integer", nullable=false)
     * @ORM\ManyToOne(targetEntity="FoodGroup")
     * @ORM\JoinColumn(name="food_group", referencedColumnName="id")
     */
    private $foodGroup;

    /**
     * @var string
     *
     * @ORM\Column(name="name", type="string", length=100, nullable=false)
     */
    private $name;



    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set foodGroup
     *
     * @param integer $foodGroup
     * @return GroceryItem
     */
    public function setFoodGroup($foodGroup)
    {
        $this->foodGroup = $foodGroup;

        return $this;
    }

    /**
     * Get foodGroup
     *
     * @return integer 
     */
    public function getFoodGroup()
    {
        return $this->foodGroup;
    }

    /**
     * Set name
     *
     * @param string $name
     * @return GroceryItem
     */
    public function setName($name)
    {
        $this->name = $name;

        return $this;
    }

    /**
     * Get name
     *
     * @return string 
     */
    public function getName()
    {
        return $this->name;
    }
}
