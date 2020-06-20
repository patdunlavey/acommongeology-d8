<?php

/**
 * @file
 * Custom theme hooks.
 */


/**
 * Implements template_preprocess_html().
 */
function acg_preprocess_html(&$variables) {

  foreach (\Drupal::routeMatch()->getParameters() as $param) {
    if ($param instanceof \Drupal\Core\Entity\EntityInterface) {
      $entity_type = $param->getEntityType()->id();
      $bundle = $param->bundle();
      $id = $param->id();
      $variables['attributes']['class'][] = 'page-' . $entity_type;
      $variables['attributes']['class'][] = 'page-' . $entity_type . '-' . $bundle;
      $variables['attributes']['class'][] = 'page-' . $entity_type . '-' . $bundle . '-' . $id;
    }
  }
}

function acg_preprocess_page(&$vars) {

  $vars['page']['classes'] = array();
  if (!empty($vars['is_front'])) {
    $vars['page']['classes'][] = 'is-front';
  }
}
