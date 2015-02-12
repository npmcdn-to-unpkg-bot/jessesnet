<?php

namespace Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * GroceryItem
 *
 * @ORM\Table(name="grocery_item")
 * @ORM\Entity
 */
class GroceryItem
{
    /**
     * @var boolean
     *
     * @ORM\Column(name="id", type="boolean", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var boolean
     *
     * @ORM\Column(name="food_group", type="boolean", nullable=false)
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
     * @return boolean 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set foodGroup
     *
     * @param boolean $foodGroup
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
     * @return boolean 
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
